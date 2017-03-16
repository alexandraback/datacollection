'''
This script would have template for reading and writing files for the google code jam thing.

@author: nanda
'''
##############################################################################
class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned 
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      try:
         return self.cache[args]
      except KeyError:
         value = self.func(*args)
         self.cache[args] = value
         return value
      except TypeError:
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)
#############################################################################
key_chest_map = {}
##############################################################################
import copy
paths = []
def sorter(a, b):
    if not (key_chest_map.has_key(a) and key_chest_map.has_key(b)):
        return 1
    if key_chest_map[a][0] > key_chest_map[b][0]:
        return 1
    else:
        return -1 

def update_paths(chest_store, keys, path):
    print chest_store, keys, path
    if len(chest_store) == 0:
        return path
    
    if len(keys) == 0:
        return False
    
    result = False
    #print keys, key_chest_map
    keys = sorted(keys, cmp=sorter)
    #print keys, key_chest_map
    for key in keys:
        if not key_chest_map.has_key(key):
            continue
        for chest in key_chest_map[key]:
            if chest_store.has_key(chest):
                x_path = copy.deepcopy(path)
                x_path.append(chest + 1)
                x_keys = copy.deepcopy(keys)
                x_chest_store = copy.deepcopy(chest_store)
                x_keys = x_keys[1:]
                x_keys.extend(x_chest_store[chest])
                del(x_chest_store[chest])
                x_path = update_paths(x_chest_store, x_keys, x_path)
                if x_path is False:                    
                    continue
                else:
                    path = map(lambda x: str(x), x_path)
                    return path
#                     return " ".join(result)
#                     if result is not None:
#                         paths.append(result)

    return path
# This part would contain the logic for solving actual puzzle.
def solve_puzzle(chest_map, chest_store, keys):
    # chest_map {no->[key_type, hidden_keys]}
    # chest_map {no->[hidden_keys]}
    # keys (existing keys)
    # key_chest_map (key can open what all chest)
    global paths
    paths = []
    
    print chest_map, chest_store, keys, key_chest_map
    result = update_paths(chest_store, keys, [])
    print result
    
    if result == []:
        return "IMPOSSIBLE"
    else:
        return " ".join(result)
#     if len(paths) > 0:
#         path = map(lambda x: str(x), sorted(paths)[0])
#         return " ".join(path)
#     else:
#         return "IMPOSSIBLE"
##############################################################################
def main():
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    # Code for Reading and writing.
    # Small Files.
    in_file_name = "D-small-attempt5.in"
    #in_file_name = "Test.in"
    out_file_name = "D-small-attempt5.out"
    #out_file_name = "Test.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    cases = int(reader.readline().strip())
    for i in range(cases):
        n_keys, n_chests = reader.readline().strip().split(" ")
        keys = reader.readline().strip().split(" ")
        #keys = map(lambda x: int(x), keys)
        
        chest_map = {}
        for x in range(int(n_chests)):
            chest_info = reader.readline().strip().split(" ")
            chest_map[x] = [chest_info[0], chest_info[2:]]
        
        global key_chest_map
        key_chest_map = {}
        for no, info in chest_map.iteritems():
            if key_chest_map.has_key(info[0]):
                key_chest_map[info[0]].append(no)
                key_chest_map[info[0]] = sorted(key_chest_map[info[0]])
            else:
                key_chest_map[info[0]] = [no]
        
        chest_store = {}
        for no, info in chest_map.iteritems():
            chest_store[no] = info[1]
        
        result = solve_puzzle(chest_map, chest_store, keys)
        print str(i+1)+ ": " + str(result)
        writer.write("Case #" + str(i+1)+ ": " + str(result) + "\n")        
    writer.close()
    
##############################################################################
if __name__== "__main__":
    main()