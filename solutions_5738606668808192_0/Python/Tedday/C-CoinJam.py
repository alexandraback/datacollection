level = "C"
file_is_small = True
attempt = 2
name = level+"-small-attempt"+str(attempt) if file_is_small else level+"-large"
input_file = file(name+".in","r")
output_file = file(name+"-output.txt","w")

def test_case():
    output = ""
    [N,J] = [int(token) for token in input_file.readline().split()]
    exponent = N/2  #Because N is even.
    #Thankfully, I don't have to pick another divisor of N
    divisors = [str(x**exponent + 1) for x in xrange(2,11)]
    start = 2**(exponent-1)+1
    for i in xrange(start,start+2*J,2):
        output += "\n" + str(bin(i)[2:]*2) + " " + " ".join(divisors)
    return output  
    
T = int(input_file.readline())
for test in xrange(T):
    out = "Case #{0}: {1}".format(test+1,test_case())
    print out
    output_file.write(out + "\n")
input_file.close()
output_file.close()
