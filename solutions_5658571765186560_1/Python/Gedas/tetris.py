name="D-large"

def solve(n,x,y):
    if n==1: return False #Duh
    if (x*y)%n<>0: return True #Duh
    if n==2: return False #Only one omino, no win except by the above condition
    if n>=7: return True #Make a hollow omino, no way to fill it, even if it fits
    if n>max(x,y): return True #Make a long straight, no way to fit it in
    if (n+1)//2>min(x,y): return True #Make stairs, no way to fit it in
    if (n+1)//2==min(x,y): #Edge case, can make an omino where it partitions grid into two but can be placed, success depends on grid size
        if n==4 or n==6 or (n==5 and max(x,y)==5): return True 
    #3 - can make only one omino, which can fill any grid subject to rule two
    #4 - make stairs, always divide an 2x*2 grid into odd numbered spaces
    #5 - make stairs, cannot divide a 3*5 into 5 and 5, can always divide all other 5x*3 into 10 and 15+.
    #6 - make stairs, will always divide into spaces non-divisable by 3
    return False #otherwise no way to win, can always place anywhere, and freely fill the space with whatever ominos
        
   


inFile=open(name+'.in','r')
outFile=open(name+'.out','w')
#Validation is considered out of scope for the exercise and will be willfully omitted
inFile.readline()

for n in xrange(1,101):
    data=map(int,str.split(inFile.readline()))
    if data==[]: break
    
    outFile.write("Case #"+str(n)+": "+("RICHARD" if solve(data[0],data[1],data[2]) else "GABRIEL")+"\n")

inFile.close()
outFile.close()
print "Done."
