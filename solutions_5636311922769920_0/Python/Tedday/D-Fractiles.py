level = "D"
file_is_small = True
attempt = 0
name = level+"-small-attempt"+str(attempt) if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")

def index(K,ints):
    ind = 0
    for i in ints:
        ind *= K
        ind += (i-1)
    return ind + 1
        

def test_case():
    [K,C,S] = [int(token) for token in input_file.readline().split()]
    if(C*S < K):
        return "IMPOSSIBLE"
    out = []
    indices = range(1,K+1)
    L = (K+C-1)/C
    for i in xrange(L):
        out.append(index(K,indices[C*i:C*(i+1)]))
    return " ".join([str(x) for x in out])
       
T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    #print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
