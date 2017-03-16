from math import *

fu=open('C-small-attempt1.in','r')
pro=(fu)

out=''


N=int(pro.readline())

#memo={}
def prob(numTribes,problem):
    tribelist=[]
    attacks=[]
    for i in range(numTribes):
        temp=problem.readline().split()

        d=int(temp[0])
        n=int(temp[1])

        w=int(temp[2])
        e=int(temp[3])

        s=int(temp[4])
        dd=int(temp[5])
        dp=int(temp[6])
        ds=int(temp[7])
        
        tribelist.append( [int(j) for j in temp])
        for j in range(n):
            attacks.append( (d +j*dd,w + dp*j,e + dp*j, s+ds*j) )

    attacks.sort()
    wall=[0 for _ in range(1000)]

    fails=0
    repairs=[]
    for i in range(len(attacks)):
#        print wall[ attacks[i][1]:attacks[i][2] ]
#        print attacks[i][3]
        if min(wall[ attacks[i][1]+500:attacks[i][2]+500 ]) <attacks[i][3]:
            fails+=1
            repairs.append( (attacks[i][1]+500,attacks[i][2]+500 ,attacks[i][3]) )

        if i+1 <len(attacks) and  attacks[i][0]<attacks[i+1][0]:
            for j in repairs:
                for w in range(j[0],j[1]):
                    wall[w]=max(wall[w],j[2])
            repairs=[]
            
    return fails
        

    


for n in range(N):
    rawr= pro.readline().split()

    numTribes= int(rawr[0])


    out=out + 'Case #%d: '%(n+1) + str(prob(numTribes,pro)) + '\n'

print out

f=open('output','w')
f.write(out)
f.close()
fu.close()


