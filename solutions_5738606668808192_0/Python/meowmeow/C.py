from itertools import combinations as combinations
#F = open('B-small-attempt0.in')
O = open('C-small-attempt0.out','w')

#F = open('B-large.in')
#O = open('B-large.out','w')

N = 16
J = 50

even = [1,3,5,7,9,11,13]
odd = [2,4,6,8,10,12,14]

gen = 1
div = ' 3 4 5 6 7 8 9 10 11\n'

O.write('Case #%d:\n'%(1))
O.write('1'+'0'*14+'1' + div)


for e in even:
    for o in odd:
        string = ''
        for index in range(N):
            if index == 0:
                string += '1'
            elif index == N-1:
                string += '1'
            elif index == e or index == o:
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
    
        
