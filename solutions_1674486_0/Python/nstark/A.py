



def solve(cs):
    for i in range(len(cs)):
        ds = set()
        todo = [i]
        while todo:
            c = todo.pop(0)
            for child in cs[c]:
                if child in ds:
                    return 'Yes'
                ds.add(child)
                todo.append(child)
    return 'No'


if __name__ == '__main__':

    n = input()
    for i in range(n):
        m = input()
        cs = []
        for j in range(m):
            cs.append([int(n)-1 for n in raw_input().split()[1:]])
        print 'Case #%s:' % (i+1), solve(cs)
    
