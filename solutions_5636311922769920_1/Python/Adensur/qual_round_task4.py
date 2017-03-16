#function to return index of a tile in K**C artwork, that has information about "gold" of [i1,i2,i3,...,ic] tiles;
#input indices - i1,i2 etc are the indices of the tiles, starting with 0 (0 - 0th tile, 1 - 1th tile etc)
#output final index numerates from 1: 1,2,3,... to match the condition of the problem
def Index(tile_inds,K,C):
    res=1      
    power=C-1
    for ind in tile_inds:
        res+=K**power*ind
        power-=1
    return res
print Index([0,1,2],K=8,C=3)

def readFile(f):
    result=[]
    with open(f) as handle:
        T=int(handle.readline())
        for t in range(T):
            s=map(int,handle.readline().split(" "))
            result.append(s)
    return result
data=readFile("D-large.in")


#for an artwork of complexity C, each tile contains information about C other tiles (possibly the same ones)
#So, if initial sequence is made of K tiles, we will need at least K/C+1 operations to find out if there is any gold
#For example, if K=8 and C=4, each tile (possibly) has information about 4 other tiles. 
#We need to look at 2 tiles, the first one containing info about [0,1,2,3] tiles, second one - [4,5,6,7]
def Solve(K,C,S):
    if S<math.ceil(K/float(C)):
        return "IMPOSSIBLE"
    indices_list=[]
    for i in range(S):
        indices=range(C*i,C*(i+1))
        indices=[i for i in indices if i<K]
        if len(indices)>0:
            if len(indices)<C:
                indices+=[0]*(C-len(indices))
            indices_list.append(indices) 
    #indices list now has indices for our Index function, that would return the final position of a tile 
    final_list=map(lambda x: Index(x,K,C),indices_list)
    return " ".join(map(str,final_list))

n=1
with open("output.txt","w") as handle:
    for dat in data:
        K=dat[0]
        C=dat[1]
        S=dat[2]
        res=Solve(K,C,S)
        string="Case #%s: %s\n"%(n,res)
        print string
        handle.write(string)
        n+=1