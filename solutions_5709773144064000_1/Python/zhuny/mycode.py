def do():
    count = input()
    for i in xrange(count):
        print "Case #%d:"%(i+1),
        calculate()

def calculate():
    C,F,X = map(float,raw_input().split())
    
    increase = 2.0
    time_count = 0.0
    while X/increase > C/increase + X/(increase+F):
        time_count += C/increase
        increase += F
    time_count += X/increase
    print time_count

if __name__ == '__main__':
    do()
