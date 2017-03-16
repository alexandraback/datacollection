def sheep(n):
    if n == 0:
        return 'INSOMNIA'
    
    seen = set()
    i = 1
    c = n
    while True:
        seen.update(str(c))
        if len(seen) == 10:
            return c
        i += 1
        c += n
        
if __name__ == '__main__':
    cases = int(input())
    for i in range(cases):
        print("Case #%s: %s" % (i+1, sheep(input())))
