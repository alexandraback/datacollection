import itertools
def NonePrime(a,b):
    return a%(b+1)==0
    
lines=raw_input()

for line_idx in xrange(1,int(lines)+1):
    print "Case #{}:".format(line_idx)

    jamcoin_len,jamcoin_type=[int(s) for s in raw_input().split(" ")]

    middle_len=jamcoin_len-2

    count=0
    for i in itertools.product([0,1],repeat=middle_len):
        s='1'+''.join(map(str,i))+'1'
        divisor=[]
        for base in xrange(2,11):
            interpret=int(s,base)
            
            if NonePrime(interpret,base):
                mindiv=base+1
                divisor.append(mindiv)

        if len(divisor)==9:
            count+=1
            divisor=map(str,divisor)
            print s+" "+" ".join(divisor)
            if count==jamcoin_type:
                break

            
        
            

            

    



        
    

    
  
