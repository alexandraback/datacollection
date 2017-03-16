level = __file__.split("\\")[-1][0]
file_is_small = False
attempt = 2
name = level+"-small-attempt"+str(attempt) if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")

def test_case():
    [B,M] = [int(i) for i in input_file.readline().split()]
    if(M > (1 << (B-2))): return "IMPOSSIBLE"
    s = "POSSIBLE"
    M -= 1
    for i in xrange(1,B):
        if(i == 1):
            s += "\n" + "0"*i + "1"*(B-i)
        else:
            s += "\n" + "0"*i + "1"*(B-1-i) + str(M % 2)
            M /= 2
    s += "\n" + "0"*B
    
    return s
                
    
T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    #print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
