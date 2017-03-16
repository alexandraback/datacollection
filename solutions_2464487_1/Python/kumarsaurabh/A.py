def getEstimate(r, t):
    est = t/(2*r)
    while (2*r*est + 2*est*est - est) > t:
        est = est/2
            
    return est
  
def prepare_input(input_file):
    test_case_count = int(input_file.readline())  #number of test cases
    
    output_file = file("A-large.out", "w")
    
    for test_case_counter in xrange(test_case_count):
        lines1 = (input_file.readline().replace('\n','')).split(' ')
        r = int(lines1[0])
        t = int(lines1[1])
        #print r, t
        
        #n = (t - 2*r + 1)/2
        #rest = 1
        #i = 0
        #while t > 0:
        #    t = t - (2*r + rest)
        #    rest = rest + 4
        #    i = i + 1
            
        #if t == 0:
        #    i = i+1
        
        est = getEstimate(r, t)
        n = 0
        origr = r
        while est > 0:
            #print est, r, t
            n = n + est
            t = t - (2*r*est + 2*est*est - est)
            r = origr + 2 * n
            est = getEstimate(r, t)
        #lowest count will be the number of switches in the server
        output_file.write("Case #"+str(test_case_counter+1)+": "+ str(n)+"\n") 

    output_file.close()
    
if __name__ == "__main__":
    input_file = file("A-large.in")
    prepare_input(input_file)
