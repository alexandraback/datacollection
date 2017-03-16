##fi = open('sample.in', 'r')
##fo = open('sample.out', 'w')
fi = open('B-small-attempt1.in', 'r')
fo = open('B-small-attempt1.out', 'w')
##fi = open('B-large.in', 'r')
##fo = open('B-large.out', 'w')

tc = int(fi.readline())
for i in range(tc):
    nums = fi.readline().split()
    n, m = int(nums[0]), int(nums[1])
    
    grass = []
    for j in range(n):
        grass.append([])
        nums = fi.readline().split()
        for k in range(m):
            grass[j].append(int(nums[k]))

    mir = []
    for j in range(n):
        mir.append(grass[j][0])

    mic = []
    for j in range(m):
        mic.append(grass[0][j])

    for j in range(n):
        for k in range(m):
            if grass[j][k] > mir[j]:
                mir[j] = grass[j][k]
            if grass[j][k] > mic[k]:
                mic[k] = grass[j][k]

    possible = True
    for j in range(n):
        for k in range(m):
            if grass[j][k] < mir[j] and grass[j][k] < mic[k]:
                possible = False
                break

    if possible:
        fo.write('Case #' + str(i+1) + ': YES\n')
    else:
        fo.write('Case #' + str(i+1) + ': NO\n')

        
fi.close()
fo.close()
