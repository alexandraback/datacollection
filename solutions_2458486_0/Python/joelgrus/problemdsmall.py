infile = "D-small-attempt2.in"
outfile = "D-small.out"
lines = [l.strip() for l in open(infile,"r")]

outf = open(outfile,"w")#

from collections import defaultdict, Counter, namedtuple

T = int(lines[0])
lines = lines[1:]

# a heuristic to eliminate unsolvable combinations
def clearly_unsolvable(chests,start_keys):
    # if there aren't enough keys, we can't solve it
    required_key_counts = Counter([c[1] for c in chests])
    available_keys = start_keys.copy()
    for c in chests:
        for k in c[2]:
            available_keys[k] = available_keys.get(k,0) + 1
    if any([available_keys.get(k,0) < c
        for k,c in required_key_counts.iteritems()
        ]):
        return True
    
    # if every key is behind its own door, then we can't solve it
    for k,c in required_key_counts.iteritems():
        if k not in start_keys and all([ch[1] == k
                                        for ch in chests
                                        if k in ch[2]]):
            return True

    return False

def solve(my_keys, # should be counter
          remaining_chests, # a list of chests
          chests_so_far): # indexes
    #print
    #print "SOLVING"
    #print "chests so far",chests_so_far
    #print "keys",my_keys
    #print "remaining_chests",remaining_chests
    num_remaining_chests = len(remaining_chests)
    #print "# remaining chests",num_remaining_chests
    if not remaining_chests:
        #print "no chests left!"
        return chests_so_far
    if not my_keys:
        #print "no keys left!"
        return False
    if clearly_unsolvable(remaining_chests,my_keys):
        return False
    # otherwise there are chests and keys, we want to lexicograph
    for i in range(num_remaining_chests):
        #print "trying chest #",i
        chest_number,required_key,keys_inside = remaining_chests[i]
        #print chest_number,required_key,keys_inside
        if required_key not in my_keys:
            pass#print "don't have key",required_key,"for chest",remaining_chests[i]
        else:
            # otherwise I have the key        
            other_chests = remaining_chests[:i] + remaining_chests[i+1:]
            my_new_keys = my_keys.copy()
            if my_keys[required_key] == 1:
                my_new_keys.pop(required_key)
            else:
                my_new_keys[required_key] = my_new_keys[required_key] - 1
            for k in keys_inside:
                my_new_keys[k] = my_new_keys.get(k,0) + 1
            #print "descending into",chests_so_far,chest_number
            result = solve(my_new_keys,other_chests,chests_so_far + [chest_number])
            #print "emerging out of",chests_so_far,chest_number
            #print "result",result
            if result:
                return result
    return False

def chest_from(line,i):
    nums = [int(c) for c in line.split()]
    return (i,nums[0],nums[2:])

for loop in range(T):
    K,N = [int(c) for c in lines[0].split()]
    lines = lines[1:]
    
    start_keys = Counter([int(c) for c in lines[0].split()])
    lines = lines[1:]

    chest_lines = lines[:N]
    lines = lines[N:]

    chests = [chest_from(chest_lines[i],i)
              for i in range(N)]

    # a simple sanity check:

    if clearly_unsolvable(chests,start_keys):
        result = None
    else:
        result = solve(start_keys,chests,[])


    if result:
        result = " ".join([str(i+1) for i in result])
    else:
        result = "IMPOSSIBLE"
        
    outstr = "Case #" + str(loop+1) + ": " + result
    print outstr
    outf.write(outstr + "\n")

outf.close()
