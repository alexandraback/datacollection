from itertools import combinations as combinations
#F = open('B-small-attempt0.in')
O = open('C-large.out','w')

#F = open('B-large.in')
#O = open('B-large.out','w')

N = 32
J = 500

even = list(2*i+1 for i in range(0,15))
odd = list(2*i+2 for i in range(0,15))

gen = 1
div = ' 3 4 5 6 7 8 9 10 11\n'

O.write('Case #%d:\n'%(1))
O.write('1'+'0'*30+'1' + div)


for e in combinations(even,2):
    for o in combinations(odd,2):
        string = ''
        for index in range(N):
            if index == 0:
                string += '1'
            elif index == N-1:
                string += '1'
            elif index in e or index in o:
                string += '1'
            else:
                string += '0'
        gen += 1
        O.write(string + div)
        
        if gen == J:
            break
    if gen == J:
        break

"""
#for e in combinations(even,2):
    for o in combinations(odd,2):
        string = ''
        for index in range(N):
            if index == 0:
                string += '1'
            elif index == N-1:
                string += '1'
            elif N-1-index in e or N-1-index in o:
                string += '1'
            else:
                string += '0'
        gen += 1
        print string,e,o
        
        if gen == J:
            break


    if gen == J:
        break
                
"""  





O.close()
    
        
