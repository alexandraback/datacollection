def convert(x):
    if x == 'y':
        x = 'a'
    elif x == 'n':
        x = 'b'
    elif x == 'f':
        x = 'c'
    elif x == 'i':
        x = 'd'
    elif x == 'c':
        x = 'e'
    elif x == 'w':
        x = 'f'
    elif x == 'l':
        x = 'g'
    elif x == 'b':
        x = 'h'
    elif x == 'k':
        x = 'i'
    elif x == 'u':
        x = 'j'
    elif x == 'o':
        x = 'k'
    elif x == 'm':
        x = 'l'
    elif x == 'x':
        x = 'm'
    elif x == 's':
        x = 'n'
    elif x == 'e':
        x = 'o'
    elif x == 'v':
        x = 'p'
    elif x == 'z':
        x = 'q'
    elif x == 'p':
        x = 'r'
    elif x == 'd':
        x = 's'
    elif x == 'r':
        x = 't'
    elif x == 'j':
        x = 'u'
    elif x == 'g':
        x = 'v'
    elif x == 't':
        x = 'w'
    elif x == 'h':
        x = 'x'
    elif x == 'a':
        x = 'y'
    elif x == 'q':
        x = 'z'
    else:
        x = ' '
    return x

def string_change(ls):
    k = ''
    for i in ls:
        k = k+ convert(i)
    return(k)

infile = open('A-small-attempt1.in','r')
outfile = open('output1.txt','w')


x = int(infile.readline())
i=0
while i<x:
    outfile.write('Case #'+str(i+1)+': '+string_change(infile.readline().strip())+'\n')
    i+=1


outfile.close()
infile.close() 
    
