def smallestGood(OneStar,TwoStar,Finished,Stars):
    smallest = -1
    for j in range(0,len(TwoStar)):
        if(Finished[j]==0):
            if(smallest==-1 or TwoStar[smallest]>TwoStar[j]):
                if(OneStar[j]<=Stars):
                    smallest = j
    return smallest

def biggestGood(OneStar,TwoStar,Finished,Stars):
    biggest = -1
    for j in range(0,len(TwoStar)):
        if(Finished[j]==0):
            if(biggest==-1 or TwoStar[biggest]<TwoStar[j]):
                if(OneStar[j]<=Stars):
                    biggest = j
    return biggest
        

f = open('B-small-attempt1.in','r')

a = f.read()
f.close()
b = a.split('\n')

cases = (int)(b[0])

g = open('B.out','w')

current = 1

for i in range(0,cases):
    num_levels = (int)(b[current])
    current+=1
    OneStar = []
    TwoStar = []
    NumFinished = []
    for j in range(0,num_levels):
        t = b[current].split(' ')
        current+=1
        OneStar.append((int)(t[0]))
        TwoStar.append((int)(t[1]))
        NumFinished.append(0)

    finished = False
    NumStars = 0
    moves = 0

    while(not(finished)):
        finished = True
        for j in range(0,num_levels):
            if(NumFinished[j]<2 and TwoStar[j]<=NumStars and finished):
                finished = False
                NumStars += (2-NumFinished[j])
                NumFinished[j]=2
                moves+=1
                #print "2",i,j,NumStars
                if(i==3):
                    print j,NumStars
        if(finished):
            #for j in range(0,num_levels):
             #   if(NumFinished[j]<1 and OneStar[j]<=NumStars and finished and j==):
             #t = smallestGood(OneStar,TwoStar,NumFinished,NumStars)
             t = biggestGood(OneStar,TwoStar,NumFinished,NumStars)
             if(t!=-1):
                finished = False
                NumStars += 1
                NumFinished[t]=1
                moves+=1
                if(i==3):
                    print t,NumStars
                    #print "1",i,j,NumStars

    if(NumStars == 2*num_levels):
        g.write("Case #"+(str)(i+1)+": "+(str)(moves)+"\n")
    else:
        g.write("Case #"+(str)(i+1)+": Too Bad\n")

g.close()

