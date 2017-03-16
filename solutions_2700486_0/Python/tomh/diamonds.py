from copy import deepcopy

def stats(state,x=0,y=30): #returns a list of potential states starting from this state
    state = deepcopy(state)
    ss = []
    while True:
        if (x-1,y-1) in state and (x+1,y-1) in state:
            state.append((x,y))
            return [state]
        if (x-1,y-1) in state:
            #go right down
            y-=1
            x+=1
        elif (x+1,y-1) in state:
            #go left down
            y-=1
            x-=1
        elif (x,y-2) in state:
            #branch!
            ss.extend(stats(state,x-1,y-1))
            ss.extend(stats(state,x+1,y-1))
            break
        elif y==0:
            state.append((x,y))
            return [state]
        else:
            y-=2
    return ss

esses = [stats([])]
for i in range(0,19):
    newS = []
    for x in esses[-1]:
        newS.extend(stats(x))
    esses.append(newS)

with open('input.txt') as f:
    lines = f.readlines()
tcases = int(lines[0])

with open('output.txt','w') as f:
    for case in range(0,tcases):
        line = lines[case+1]
        n, x ,y = map(int,line.split(" "))
        num = 0
        total = 0
        for i in esses[n-1]:
            if (x,y) in i:
                num+=1
            total+=1
        result = float(num)/float(total)
        f.write("Case #" + str(case+1) + ": " + str(result) + '\n')

