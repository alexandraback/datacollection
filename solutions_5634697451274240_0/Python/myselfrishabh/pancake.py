inputf = open('B-small-attempt0.in','r')
outputf = open('pancakes-small-attempt.txt','w')
lines = inputf.readlines()
T = int(lines[0])

for i in range(1,T+1):
    flips=0
    stack = lines[i][:-1];
    for j in range(len(stack)-1):
        if stack[j]!=stack[j+1]:
            flips+=1
    if(stack[-1] is "-"):
        flips+=1
    outputf.write("Case #"+str(i)+": "+str(flips)+"\n")

inputf.close()
outputf.close()