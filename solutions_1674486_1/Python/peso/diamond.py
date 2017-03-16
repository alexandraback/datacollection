import sys
import string

# Arguments: [in] [out]
# Defaults: in='input.txt', out=stdout



def has_diamond():
    def find_diamond(c):
        # Follow all parents from c recursively
        # Then mark c as seen
        todo = []
        todo.append(c)
        while len(todo) > 0:
            b = todo.pop()
            if b in seen:
                return True
            seen[b] = True
            todo.extend(p[b])
        return False
    
    def find_roots():
        before = {}
        for c in p.keys():
            for b in p[c]:
                before[b] = c
        return  filter(lambda c: c not in before.keys(), p.keys())

    for c in find_roots():
        seen = {}
        if find_diamond(c):
            return True
    return False
        

if len(sys.argv) > 1:
    input_file = len(sys.argv)>1 and sys.argv[1] or 'input.txt'
    outf = len(sys.argv)>2 and open(sys.argv[2],'w') or sys.stdout
    with open(input_file) as f:
        T = int(f.readline())
        for x in range(T):
            N = int(f.readline()) ## classes
            p = {}

            for c in range(1,N+1):
                P = map(int, f.readline().split(' '))
                p[c] = P[1:]

            outf.write('Case #{0}: '.format(x+1))
            if has_diamond():
                outf.write('Yes\n')
            else:
                outf.write('No\n')
