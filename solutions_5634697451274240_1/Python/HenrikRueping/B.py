filename  = "B-large.in"
f = open(filename,'r')
out = open("output.out",'w')
N =int(f.readline())
for i in range(N):
    S = f.readline().strip()+'+'
    count= 0
    for j  in range(len(S)-1):
        if S[j]!=S[j+1]:
            count+=1
    out.write("Case #"+str(i+1)+": "+str(count)+"\n")
    
f.close()
out.close()
