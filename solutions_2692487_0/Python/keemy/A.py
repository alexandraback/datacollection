fu=open('A.in','r')
prob=(fu)

out=''


N=int(prob.readline())


def num_changes(size,enemies, depth=1):
    if size==1:
        return len(enemies)
    if depth==500:
        print("fuuu")
    if len(enemies)==0:
        return 0

    enemies.sort()
    i=0
    while i< len(enemies) and enemies[i]<size:
        size+=enemies[i]
        i+=1
        
    enemies=enemies[i:]
    
    if i>0:
        return num_changes(size,enemies,depth+1)
    else:
        return 1+min( num_changes(size,enemies[:-1],depth+1), num_changes(2*size+-1,enemies,depth+1))
    





for n in range(N):
    size= int(prob.readline().split()[0])
    enemies= [int(j) for j in prob.readline().split()]

    out=out + 'Case #%d: '%(n+1) + str(num_changes(size,enemies)) + '\n'
    print out

print out

f=open('output','w')
f.write(out)
f.close()
fu.close()


