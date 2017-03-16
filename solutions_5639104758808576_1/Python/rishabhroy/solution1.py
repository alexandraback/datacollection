#rishabh s solution
g = open('ovation_large_out.txt','w+')

with open('A-large.in', 'r+') as f:
    num_cases = int(f.readline())

    for i in range(num_cases):
        shy, mycrowd = f.readline().split(' ')
        mycrowd = list(mycrowd)[:-1]
        stands = 0
        num_friends = 0

        for j, k in enumerate(mycrowd):
            if stands >= j:
                stands += int(k)
            else:
                num_friends += (j - stands)
                stands += (int(k) + (j - stands))

        g.write('Case #' + str(i+1) + ': ' + str(num_friends) + '\n')

g.close()