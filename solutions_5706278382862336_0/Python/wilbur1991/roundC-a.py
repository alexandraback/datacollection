import string   

def  gongyue(m,n):
    if n==0:
        return m;
    else:
        return gongyue(n,m%n);

    
f=open('F:/A-small-attempt1.in')
fw=open('F:/A-large-attempt1.out','w')
caseNum = string.atoi(f.readline())    
for case in range(caseNum): 
    list =   f.readline().strip().split("/")
    a = string.atoi(list[0])
    num = string.atoi(list[1])
    factor = gongyue(a,num)
    a /= factor
    num /= factor
    
    result = 0

    if (num & (num-1)) ==0:
        while(num >1 ):  
            if(a > num ):
                break
            num /= 2
            result += 1 
    else:
        result = 'impossible'
    fw.write("Case #{0}: {1}\n".format(case+1,result))    
fw.close()
f.close()
            
    