from operator import add

def containers(N, balls):
    if N == 1: return [[balls]]
    el = []
    for x in range(balls+1):
        for nel in containers(N-1, balls-x):
            el.append([x]+nel)
    return el

def symcoins(N):
    for boxes, balls in enumerate(range(N-4, 0, -2)):
        for pattern in containers(boxes+1, balls):
            string = '11' + '11'.join(map(lambda x: '0'*x, pattern)) + '11'
            yield string
        
def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        N, J = map(int, raw_input().split())
        print "Case #%i:" %case
        for i,x in enumerate(symcoins(N)):
            if i == J: break
            print ' '.join([x]+map(lambda x: str(int('11', x)), range(2,11)))

if __name__ == '__main__':
   main()
