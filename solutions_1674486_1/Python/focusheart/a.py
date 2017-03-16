fns = ['A-practice',
  'A-small-attempt0',
  'A-small-attempt1',
  'A-small-attempt2',
  'A-small-attempt3',
  'A-large',
  ]
fn = fns[5]
fi = open('%s.in.txt' % fn, 'r')
fo = open('%s.out' % fn, 'w')
t = int(fi.readline())

for i in range(t):
    n = int(fi.readline())
    cs = range(n+1)
    pcs = []
    for j in range(n):
        tmp = map(lambda x:int(x), fi.readline().split(' '))
        cs[j+1] = tmp[1:]
        if tmp[0]>1:
            pcs.append(j+1)
    if len(pcs)==0:
        print 'Case #%s: No' % (i+1)
        fo.write('Case #%s: No\n' % (i+1))
        continue
    find = False
    for j in pcs:
        visited = [0 for tmp in range(n+1)]
        curs = [j]
        while curs!=[]:
            nodes = cs[curs.pop(0)]
            for node in nodes:
                if visited[node]==1:
                    find = True
                    break
                elif visited[node]==0:
                    visited[node]=1
                    curs.append(node)
            if find:
                break;

        if find:
            print 'Case #%s: Yes' % (i+1)
            fo.write('Case #%s: Yes\n' % (i+1))
            break

    if find:
        pass
    else:
        print 'Case #%s: No' % (i+1)
        fo.write('Case #%s: No\n' % (i+1))


fi.close()
fo.close()
