def trans(char):
    return ord(char) - ord('A')

# map(int,F.readline().rstrip().split())

#F = open('A-small-attempt0.in')
#O = open('A-small-attempt0.out','w')

F = open('A-large.in')
O = open('A-large.out','w')


T = int(F.readline())

print T


for case in range(1,T+1):
    string = F.readline().rstrip()

    store = [0] * 26

    for i in string:
        store[ord(i) - ord('A')] += 1


    zero = store[trans('Z')]
    store[trans('Z')] -= zero
    store[trans('E')] -= zero
    store[trans('R')] -= zero
    store[trans('O')] -= zero


    six = store[trans('X')]

    store[trans('S')] -= six
    store[trans('I')] -= six
    store[trans('X')] -= six

    # one two three four five seven eight nine

    two = store[trans('W')]

    store[trans('T')] -= two
    store[trans('W')] -= two
    store[trans('O')] -= two

    
    # one three four five seven eight nine

    eight = store[trans('G')]

    store[trans('E')] -= eight
    store[trans('I')] -= eight
    store[trans('G')] -= eight
    store[trans('H')] -= eight
    store[trans('T')] -= eight
    
    # one three four five seven nine

    seven = store[trans('S')]

    store[trans('S')] -= seven
    store[trans('E')] -= seven
    store[trans('V')] -= seven
    store[trans('E')] -= seven
    store[trans('N')] -= seven

    
    # one three four five  nine

    five = store[trans('V')]

    store[trans('F')] -= five
    store[trans('I')] -= five
    store[trans('V')] -= five
    store[trans('E')] -= five

    # one three four nine

    
    four = store[trans('F')]

    store[trans('F')] -= four
    store[trans('O')] -= four
    store[trans('U')] -= four
    store[trans('R')] -= four

    # one three nine

    nine = store[trans('I')]
    three = store[trans('T')]
    one = store[trans('O')]

    
    ans = '0'*zero +'1'*one+'2'*two+'3'*three+'4'*four+'5'*five+'6'*six+'7'*seven+'8'*eight+'9'*nine
        


    #print ans

    O.write('Case #%d: %s\n'%(case,ans))
        
        
                
                
        



F.close()
O.close()
    
        
