import sys
#sys.stdout = open("out.txt", "w")

def solve(topics):
    first,last = [[] for i in range(len(topics))],[[] for i in range(len(topics))]
    for i in range(len(topics)):
        for j in range(i+1,len(topics)):
            f,l = topics[i][0],topics[i][1]
            if topics[i][0] == topics[j][0]:
                first[i].append(j)
                first[j].append(i)
            if topics[i][1] == topics[j][1]:
                last[i].append(j)
                last[j].append(i)
    l = len(topics)
    ans = 0
    for i in range(l):
        for j in range(l):
            for k in range(l):
                if k in first[i] and k in last[j]:
                    ans+=1
    return ans
        
    

lines = []

with open("C-small-attempt0.in", "r") as f:
    lines = f.readlines()
ctr = 0

t = int(lines[ctr])
ctr+=1
l=""
for i in range(1, t+1):
    n = int(lines[ctr])
    ctr+=1
    topics = []
    for j in range(n):
        x = lines[ctr].strip().split()
        topics.append((x[0],x[1]))
        ctr+=1
    ans = solve(topics)
    l+="Case #{}: {}\n".format(i, str(ans))

with open("out.txt","w") as f:
    f.write(l)
