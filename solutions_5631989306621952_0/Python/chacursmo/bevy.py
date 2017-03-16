#!/usr/local/bin/python




def main():
    import sys

    T = sys.stdin.readline()
    i = 1
    for line in sys.stdin.readlines():
        
        mojo(line,i)
        i+=1


def mojo(line,iter):
    w =list(line)
    a = list(w[0])
    aprev = None
    for l in range(1,len(w)):
        if w[l] < a[0]:
            a.append(w[l])
            aprev=w[l]
        else :
            a.insert(0,w[l])
            aprev=w[l]
    print 'Case #'+str(iter)+':',
    print ''.join(a),
        
if __name__ == "__main__":
    main()
