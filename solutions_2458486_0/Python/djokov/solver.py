#file = open('input.in')
file = open('D-small-attempt2.in')
lines = file.readlines()
examples = int(lines[0].strip())
chest_key = []
keys_in_chest = []    
def get_start_keys(index):
    return lines[index].split()

def get_openable_chests(keys, chest_open):
    openable_chests = []
    for i in range(len(chest_open)):
        if chest_open[i] == False and keys.count(chest_key[i]) > 0:
            openable_chests.append(i)
    return openable_chests

def remove_key(keys, key_value):
    for i in range(len(keys)):
        if key_value == keys[i]:
            keys.pop(i)
            break

def worth_going(keys, chest_open):
    all_keys = keys
    needed_keys = []
    for i in range(len(chest_open)):
        if chest_open[i]==False:
            all_keys = all_keys + keys_in_chest[i]
            needed_keys.append(chest_key[i])
            
    for key in set(needed_keys):
        keys_available = all_keys.count(key)
        
        conceled = 0
        for i in range(len(chest_open)):
            if chest_open[i]==False and (keys_in_chest[i].count(key) == 1) and chest_key[i]==key:
                conceled += 1
        
        if conceled == keys_available:
            return False
                                
        if keys_available < needed_keys.count(key):
            return False
            
        
    return True
            
def rec_solve(keys, chest_open, traj):
    #print traj
    #print keys, chest_open, traj
    if worth_going(keys, chest_open) == False:
        #print "Not worth it"
        return []
    if chest_open.count(False) == 0:
        return traj
    else:
        openable_chests = get_openable_chests(keys, chest_open)
        for chest in openable_chests:            
            new_keys = keys + keys_in_chest[chest]
            remove_key(new_keys, chest_key[chest])
            new_chest_open = list(chest_open)
            new_chest_open[chest] = True
            new_traj = list(traj)
            new_traj.append(chest)
            res = rec_solve(new_keys, new_chest_open, new_traj)
            if len(res) > 0:
                return res
    return []

def show_result(index, result):
    if len(result) > 0:
        print >> out,  "Case #"+str(index+1)+":", " ".join([str(r+1) for r in result])  
    else:
        print >> out,  "Case #"+str(index+1)+":", "IMPOSSIBLE"

def solve(index):
    global chest_key
    global keys_in_chest
    chest_key = []
    keys = []
    keys_in_chest = []
    splits = lines[current].split(" ")
    keys = get_start_keys(current + 1)
    chests = int(splits[1])
    chest_open = [False]*chests
    
    for j in range(chests):
        row_split = lines[current+2+j].strip().split(" ")
        chest_key.append(row_split[0])
        temp_keys = []
        for k in range(2,2+int(row_split[1])):
            temp_keys.append(row_split[k])
        keys_in_chest.append(temp_keys)
    #print keys
    #for i in range(len(chest_key)):
    #    print i, chest_key[i], keys_in_chest[i]
    res = rec_solve(keys, chest_open, [])        
    return res
    
out = open("results.out", "w")    
current = 1
for i in range(examples):
    #print i
    splits = lines[current].split(" ")
    chests = int(splits[1])    
    show_result(i, solve(i))
    current = current + chests + 2
    #print "---------------"    

