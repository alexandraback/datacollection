from collections import Counter
import IPython

MIN = 0
MAX = 999999

letters = 'a b c d e f g h i j k l m n o p q r s t u v w x y z'.split()



dictionary = {}
for i in range(1, 11):
    dictionary[i] = []
    #for l in letters:
    #    dictionary[i][l] = []

#if True:
#    f = open('garbled_email_dictionary.txt', 'r')
#    for line in f.readlines():
#        l = line.strip()
#        size = len(l)
#        start = l[0]
#        dictionary[size][start].append(l)

dictionary_dict = {}

if True:
    f = open('garbled_email_dictionary.txt', 'r')
    for line in f.readlines():
        l = line.strip()
        size = len(l)
        dictionary[size].append(l)
        dictionary_dict[l] = True
#        start = l[0]
#        dictionary[size][start].append(l)


        
#IPython.embed()

#letter_map = {}
#c = 0
#for letter in letters:
#    letter_map[letter] = c
#    c += 1

#neibors = {}
#for letter in letters:
#    neibors[letter] = [] 
#    for letter2 in letters:
#        if abs(letter2 - letter) < 

def compare(x):

    result = MAX

    size = len(x)

    if x in dictionary_dict: return 0

    for d in dictionary[size]:
        last_diff = -9999999
        count = 0
        is_ok = True
        for i in range(size):
            if d[i] != x[i]:
                if i - last_diff < 5:
                    is_ok = False
                    break
                count += 1 
                last_diff = i
        if is_ok:
            if count < result: result = count

    #print x, result

    return result

def solve(S):

    size = len(S)

    m = [MAX for i in range(len(S))]

    for i in range(size):
        print '===', S[i], '==='

        for j in range(1, 11):
            
            start = i - j + 1
            if start < 0: continue

            if start == 0: last = 0
            else: last = m[start-1]

            tmp = last + compare(S[start: i+1])
            #print S[start:i+1], last, compare(S[start:i+1]), tmp
            if tmp < m[i]: m[i] = tmp


    print m, m[-1]
    
    return m[-1]

if __name__ == '__main__':

    import sys
    
    input_file = sys.argv[1]

    start = int(sys.argv[2])
    end = int(sys.argv[3])

    output_file = input_file[:].replace('.in', '.out') + str(start)

    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')

    T, = [int(x) for x in f_in.readline().split()]

    for case in range(1, T+1):
        print 
        print '====================='
        print '    ' + str(case)
        print '====================='

        S = f_in.readline().strip()

        if not (start <= case <= end): continue

        print S

        # Solve
        ans = solve(S)

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        
        
