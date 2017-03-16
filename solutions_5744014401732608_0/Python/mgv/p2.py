possible = []
for i in xrange(50):
    if i == 0 or i == 1:
        possible.append(0)
    else:
        possible.append(possible[i-1] + possible[i-2]+1)
        
num_test = int(raw_input())
for test_case in xrange(1,num_test+1):
    input_data = raw_input().split()
    B = int(input_data[0])
    M = int(input_data[1])
    
    if M > possible[B]:
        print "Case #{}: IMPOSSIBLE".format(test_case)    
    else:
        print "Case #{}: POSSIBLE".format(test_case)
        
        table = [[0]*B for i in xrange(B)]
             
        smallest = 0
        while  possible[smallest+1] <= M:
            smallest += 1
        smallest -= 1
        for i in xrange(B-smallest, B):
            table[0][i] = 1
            
        for i in xrange(B-smallest, B):
            for j in xrange(B-smallest, B):
                if i<j:
                    table[i][j] = 1
        created = possible[smallest+1]
           
        if created < M:
            index = B-smallest-1
            table[0][index] = 1
            while created < M:
                smallest = 0
                while  created + possible[smallest] <= M:
                    smallest += 1
                smallest -= 1
                table[index][B-smallest] = 1
                created += possible[smallest]
            
        res = []
        for row in table:
            for elem in row:
                res += str(elem)
            res += '\n'
        print ''.join(res),
        