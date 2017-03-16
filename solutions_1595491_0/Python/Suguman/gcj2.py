def best(l):
    best_ls = []
    for i in l:
        if i == 0:
            best_ls.append((0, 0))
        elif i%3 == 0:
            best_ls.append((i//3, i//3 + 1))
        elif i%3 == 1:
            best_ls.append((i//3 + 1, i//3 + 1))
        else:
            best_ls.append((i//3 + 1, i//3 + 2))
    return (best_ls)
            
def googlers(l, surp, min_best):
    counter = 0
    for i in l:
        if min_best <= i[0]:
            counter += 1
        else:
            if surp != 0:
                if min_best <= i[1]:
                    counter += 1
                    surp -= 1
                    
    return counter

infile = open('B-small-attempt1.in','r')
outfile = open('output2.txt','w')


x = int(infile.readline())
i=0
while i<x:
    k = infile.readline().strip().split()
    surp, min_best = int(k[1]), int(k[2])
    ls = []
    for j in range(3, len(k)):
        ls.append(int(k[j]))
    ls = best(ls)
                  
    outfile.write('Case #'+str(i+1)+': ' + str(googlers(ls, surp, min_best)) +'\n')
    i+=1


outfile.close()
infile.close() 
    
'''
infile = ('test.txt', 'r')
outfile = ('hello.txt', 'w')
x = int(infile.readline())
i = 0
while i<x:
    k = infile.readline().strip()
    print(k)
'''
