import copy
import sys
import pickle

with open("combos.pkl") as f:
  choices = pickle.load(f)
  
print "loaded"

def answer(n):

  data = [int(d) for d in n.strip().split()]
  
  bffs = {}
  for i in range(len(data)):
    bffs[i+1] = data[i]
    
  # print bffs
  
  size = len(data)

  for i in range(len(data),0,-1):
    print size, i
    options = all_choices(size, i)
    
    # print options
    # print
    

    for o in options:
      # print o
      fail = False
      for j in range(len(o)):
        kid = o[j]
        if o[j-1] != bffs[kid] and o[(j+1)%len(o)] != bffs[kid]:
          # print kid, bffs[kid], o[j-1], o[(j+1)%len(o)]
          fail = True
          break
      if fail == True:
        continue
      else:
        print "Solved:", i
        return i
    
  return 0
  
def all_choices(n, k):
  if (n,k) in choices:
    return choices[(n,k)]
    
  if k == 1:
    return [[i+1] for i in range(n)]
      
  result = []
  one_step_down = all_choices(n, k-1)
  for osd in one_step_down:
    for i in range(n):
      cp = copy.copy(osd)
      if i+1 in cp:
        continue
      else:
        result.append([i+1] + cp)
  
  choices[(n,k)] = result
  
  return result
  
def rotations_and_reversals(l):
  this = []
  for i in range(len(l)):
    this.append(l[i:] + l[:i])
    this.append(reversed(l[i:] + l[:i]))
    
  return this
  
# choices = {}
# for i in range(10):
  # print i+1
  # all_choices(i+1,i+1)
  # # with open("combos.pkl", "w") as w:
    # # pickle.dump(choices, w)
# # sys.exit()
      
# # Rebuild dictionary
# new_choices = {}
# for key in choices.keys():
  # print key
  # used_set = set([])
  # used = []
  
  # for option in choices[key]:
    # if tuple(option) in used_set:
      # continue
    # else:
      # used.append(option)
      # for rr in rotations_and_reversals(option):
        # used_set.add(tuple(rr))
      
  # new_choices[key] = used

# choices = new_choices

# with open("combos.pkl", "w") as w:
  # pickle.dump(choices, w)

  
print "beginning"
    
      
with open("C-small.in") as f:

  with open("C-small.out", "w") as w:
    f.readline()
    question = 1
    while True:
      if f.readline().strip() == "":
        break
      n = f.readline().strip()
      output = answer(n)
    
      w.write("Case #{0}: {1}\n".format(question, output))
      question += 1
     
     

  

    

