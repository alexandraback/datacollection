#test

def  calculateMotes( yoursize, othersizes):
    othersizes.sort() #now low to high
    othersizes.reverse() #now high to low
    currscore = 0
    bestscore = len(othersizes) #default: remove all
    while currscore < bestscore : #if exceeds can't do better
        nextz = othersizes.pop()
        if nextz < yoursize: #eat it
           yoursize += nextz
        else:
           removeallscore = currscore + len(othersizes)+1 #remove all including curr
           if removeallscore < bestscore:
               bestscore = removeallscore
           if yoursize == 1: #can do nada, bestscore is best so far
               break
           while yoursize <= nextz: #eat till you're bigger than it
               yoursize+= (yoursize - 1)
               currscore += 1
           yoursize += nextz #eat it
        if len(othersizes) == 0 :
            if currscore < bestscore:
                bestscore = currscore
            break
    return bestscore

data = [line.strip() for line in open("input.txt")]
output = []
count = 1
for item in data[1::2]:
    line = [int(token) for token in item.split()]
    line2 = [int(token) for token in data[count+1].split()]
    #print "line[0] and 2", line[0], line2
    output.append(calculateMotes(line[0], line2))
    count+=2

f = open("output.txt", 'w')
for i in range(len(output)):
    f.write("Case #"+str(i+1)+": "+str(output[i])+"\n")
f.close()
