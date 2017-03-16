#! /usr/bin/python
# -*- coding: utf8 -*-

def do_calc(line):
    result = []
    n = line[0]
    j = line[1:]
    x = sum(j)
    m = min(j)
    for i in j:
        k = j[:]
        k.remove(i)
        s = sum(k)
        l = len(k)
#        print i,float(s+x-l*i)/(l*x+x)
        result.append( max(float(s+x-l*i)*100/(l*x+x),0.0) )
    return result

def main():
    for c in range(input()):
        line = map(int,raw_input().split())
        ans = do_calc(line) 
        head = 'Case #%d:' % (c+1)
        print head," ".join(str("%.6f" % x) for x in ans)

if __name__ == '__main__':
    main()
