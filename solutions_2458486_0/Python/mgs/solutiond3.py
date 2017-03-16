class Node:
  future = None
  def __init__(self,location,keys):
    self.location=location
    self.keyring=keys
  def explore(self):
    #note: excludes empty chests from search.  Need to add them in later.
    self.future = [d for d in chest_locks.keys() if (self.keyring.get(chest_locks[d],0)>0 and self.location.count(d)==0 and len(chest_contents[d])>0)]
  def add_keys(self,keys):
    for k in keys:
      self.keyring[k] = self.keyring.get(k,0)+1
  def remove_key(self,k):
    self.keyring[k] = self.keyring.get(k,0)-1

#Check if a subpath (from the beginning) is valid
#subpath is a list of chest names
def validSubPath(chest_locks, chest_contents, start_keys, subpath):
  node = Node([],start_keys.copy())
  for c in subpath:
    k = chest_locks[c]
    if node.keyring.get(k,0)>0:
      node.remove_key(k)
      node.add_keys(chest_contents[c])
    else:
      return False
  return True

def solveTreasure(chest_locks, chest_contents, start_keys):
  curr_node = Node([],start_keys)
  num_chests = len(chest_locks.keys())
  empty_chests = [k for k in chest_locks.keys() if len(chest_contents[k])==0]
  num_nonempty_chests = num_chests - len(empty_chests)
  #quick rejection without enough keys:
  if (sum([len(v) for v in chest_contents.values()])+sum(start_keys.values())) < num_chests:
    return "IMPOSSIBLE"
  #quick rejection without enough keys for each lock:
  keys_needed = {}
  for chest in chest_locks.keys():
    keys_needed[chest_locks[chest]] = keys_needed.get(chest_locks[chest],0) + 1
  total_keys = start_keys.copy()
  for stuff in chest_contents.values():
    for k in stuff:
      total_keys[k] = total_keys.get(k,0)+1
  for k in keys_needed.keys():
    if total_keys.get(k,0)<keys_needed[k]:
      print "keys_needed",keys_needed
      print "total_keys",total_keys
      return "IMPOSSIBLE"
  #Now a depth first search of the nonempty chests
  history = []
  while len(curr_node.location)<num_nonempty_chests:
    #print "curr_node",curr_node.location
    if curr_node.future==None:
      curr_node.explore()
    if len(curr_node.future)==0:
      #branch is used up, go back up
      if len(history)==0:
        break
      del curr_node
      curr_node = history.pop()
      continue
    new_chest = curr_node.future.pop(0)
    new_node = Node(curr_node.location[:],curr_node.keyring.copy())
    new_node.location.append(new_chest)
    new_node.remove_key(chest_locks[new_chest])
    new_node.add_keys(chest_contents[new_chest])
    history.append(curr_node)
    curr_node = new_node
    #print "new_node",new_node.location
  if len(curr_node.location)<num_nonempty_chests:
    return "IMPOSSIBLE"
  final_path = curr_node.location
  if len(final_path) == num_chests:
    return " ".join([str(i) for i in final_path])
  #Need to insert the held out chests in the correct places
  empty_chests.sort()
  if len(final_path)==0:
    return " ".join([str(i) for i in empty_chests])
  while len(empty_chests)>0:
    chest = empty_chests.pop(0)
    for i in range(len(final_path)+1):
      if i < len(final_path) and chest > final_path[i]:
        continue
      tmppath = final_path[:]
      tmppath.insert(i,chest)
      if validSubPath(chest_locks, chest_contents, start_keys, tmppath):
        final_path.insert(i,chest)
        break
  if len(final_path) == num_chests:
    return " ".join([str(i) for i in final_path])
  else:
    return "IMPOSSIBLE"


fin = open("input.txt",'r')
fout = open("output.txt",'w')

T = int(fin.readline().strip())

for i_case in range(T):
  print "i_case",i_case
  #first, num starting keys and num chests
  [num_start,num_chests] = [int(s) for s in fin.readline().strip().split(" ")]
  #then a line of starting keys
  start_keys = {}
  for k in [int(s) for s in fin.readline().strip().split(" ")]:
    start_keys[k] = start_keys.get(k,0)+1
  #line for each chest: key, num key inside, key list
  chest_locks = {}
  chest_contents = {}
  for i in range(1,num_chests+1):
    chest_info = [int(s) for s in fin.readline().strip().split(" ")]
    chest_locks[i]=chest_info[0]
    chest_contents[i]=chest_info[2:]
  print "chest_locks",chest_locks
  print "chest_contents",chest_contents
  print "start_keys",start_keys
  result = solveTreasure(chest_locks, chest_contents, start_keys)
  print result
  fout.write("Case #"+str(i_case+1)+": "+result+"\n")

fin.close()
fout.close()

