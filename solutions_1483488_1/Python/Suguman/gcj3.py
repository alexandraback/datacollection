def digits(x):
    d = 0
    while x != 0:
        d = d+1
        x = x//10
    return d

def reverse(x):
    num = x
    y = (x%10)*10**(digits(x)-1) + x//10
    l = [y]
    while y != num:
        y = (y%10)*10**(digits(num)-1) + y//10
        l.append(y)
    return l

def screen(a, b):
    x , counter = a, 0
    while x<=b:
        rev_ls = reverse(x)
        for i in rev_ls:
            if (i>x) and (i<=b):
                counter += 1
        x += 1
    return counter

infile = open('C-large.in','r')
outfile = open('output3large.txt','w')


x = int(infile.readline())
i=0
while i<x:
    s = infile.readline().split()
    a , b = int(s[0]), int(s[1])
    outfile.write('Case #' + str(i+1) + ': ' + str(screen(a, b)) + '\n')
    i+=1

outfile.close()
infile.close() 
    
                
    
 
   


        
    
        
