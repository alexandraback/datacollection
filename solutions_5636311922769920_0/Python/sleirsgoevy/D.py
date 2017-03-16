def solve(k, c, s):
    if s < k: return "IMPOSSIBLE"
    l = k**(c-1)
    l2 = l*k
    return ' '.join(map(str, range(1, l2+1, l)))

def check():
    while True: yield None

def generate():
    import random
    ans = ['500']
    for i in range(500):
        ans.append(' '.join(map(str, (random.randint(1000), random.randint(4), random.randint(1000)))))
    return ('\n'.join(ans)+'\n', check)

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #", i+1, ": ", solve(*map(int, input().split())), sep='')

