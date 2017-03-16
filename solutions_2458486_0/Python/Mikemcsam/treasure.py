def graphSearch(requirements, opened, keys, box_treasures, cache, opened_count):
    if opened_count == len(requirements):
        return (1,[])
    if opened in cache:
        return (-1,[])
        
    for i, requirement in enumerate(requirements):
        if opened[i] == "1":
            continue
        if keys[requirement] > 0:
            keys[requirement] -= 1
            new_opened = opened[:i]+"1"+opened[i+1:]
            for key in box_treasures[i]:
                keys[key] += 1
            test,remaining = graphSearch(requirements,new_opened,keys,box_treasures, cache, opened_count + 1)
            if test == 1:
                return (1,[i] +remaining)
            keys[requirement] += 1
            for key in box_treasures[i]:
                keys[key] -= 1
    cache.add(opened)
    return (-1,[])
    
import sys
if __name__ == "__main__":
    f = sys.stdin
    tests = int(next(f).strip())
    for i in range(tests):
        num_keys,chests = [int(value) for value in next(f).split()]
        keys = [0]*201
        for key in [int(value) for value in next(f).split()]:
            keys[key]+=1
        treasures = [] 
        requirements = []
        for j in range(chests):
            chest_info = [int(value) for value in next(f).split()]
            requirements.append(chest_info[0])
            treasures.append(chest_info[2:])
        result = graphSearch(requirements, "0"*len(requirements), keys, treasures, set(),0)
        if result[0] == -1:
            print("Case #"+str(i+1)+ ": IMPOSSIBLE")
        else:
            print("Case #"+str(i+1)+ ": "+" ".join([str(number+1) for number in result[1]]))
