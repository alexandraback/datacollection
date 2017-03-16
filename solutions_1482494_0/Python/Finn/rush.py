fin = open('./B-small-attempt1.in','r')
fout = open('output','w')

N = int(fin.readline())

def solve(levels,star,time):
    flag = 0
    for level in levels:
        if(level[1]<=star and level[1]>=0):         
            if(level[0]==-1):star+=1
            else:star+=2
            flag=0
            level[1] =-1
            time+=1
            time = solve(levels,star,time)
        elif(level[1]==-1):continue
        else:flag=1
    for level in levels:
        if(level[1]==-1 or level[0]==-1):continue
        elif(level[0]<=star):
            flag=0
            star+=1
            level[0] =-1
            time+=1
            time = solve(levels,star,time)
        else:flag=1
    if(flag==0):return time
    if(flag==1):return "Too Bad"

for i in range(1,N+1):

    T = int(fin.readline())
    levels = []
    flag = []
    for t in range(0,T):
        levels.append(map(int,fin.readline().split()))
        flag.append(0)

    ones = [level[0] for level in levels]
    twos = [level[1] for level in levels]

    if(0 not in ones and 0 not in twos):ans = "Too Bad"
    else:
        currstar = 0
        starttime = 0
        time = solve(levels,currstar,starttime)
        ans = str(time)

    ans = "Case #"+str(i)+": "+ans+"\n"
    fout.write(ans)

fin.close()
fout.close()
    
    
