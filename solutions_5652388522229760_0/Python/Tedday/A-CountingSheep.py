level,file_is_small = "A",True
name = level+"-small-attempt0" if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")

def test_case():
    N = int(input_file.readline())
    if(N == 0):
        return "INSOMNIA"

    unseen = set([str(i) for i in xrange(10)])
    i = 0
    while(len(unseen) >0):
        i += 1
        for d in str(i*N):
            if(d in unseen ):
                unseen.remove(d)
    return i*N
T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    #print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
