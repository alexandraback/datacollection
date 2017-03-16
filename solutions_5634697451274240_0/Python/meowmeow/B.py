F = open('B-small-attempt0.in')
O = open('B-small-attempt0.out','w')

#F = open('B-large-practice.in')
#O = open('B-large-practice.out','w')


T = int(F.readline())

print T

for case in range(1,T+1):
    string = F.readline().rstrip().rstrip('+')

    ans = 0
    
    if string != '':
        start = string[0]
        index = 0
        while True:
            while index < len(string) and string[index] == start:
                index += 1
            ans += 1
            if index == len(string):
                break
            else:
                start = string[index]


    
    O.write('Case #%d: %d\n'%(case,ans))
    


F.close()
O.close()
    
        
