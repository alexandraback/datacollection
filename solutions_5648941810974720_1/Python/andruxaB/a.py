filename = "C:\Users\Andri_000\Downloads\python\codejam\Round 1B\A\A-large"

fin = open(filename+".in")
fout = open(filename+".out","w")

trials = int(fin.readline())

nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

for T in xrange(trials):
    
    st = fin.readline().strip()
        
    
    numcount = [0]*10
    
    numcount[0] = st.count("Z")
    numcount[2] = st.count("W")
    numcount[4] = st.count("U")
    numcount[5] = st.count("F")-numcount[4]
    numcount[6] = st.count("X")    
    numcount[8] = st.count("G")
    numcount[1] = st.count("O")-numcount[0]-numcount[2]-numcount[4]
    numcount[7] = st.count("V")-numcount[5]
    numcount[9] = st.count("I")-numcount[5]-numcount[6]-numcount[8]
    numcount[3] = st.count("H")-numcount[8]
    
    sout = ''
    for i in range(10):
        if numcount[i]>0:
            sout += str(i)*numcount[i]
    
    fout.write("Case #{0}: {1}\n".format(T+1, sout))
    #print sout
                    
fin.close()
fout.close()