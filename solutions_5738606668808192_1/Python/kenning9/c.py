import sys
count = 0;
last = 0
print "Case #1:"
while count < 500:
    var = last*2 + 1 + 2**31
    lol = "{0:b}".format(var)
    died = False;
    last += 1
    for base in range(2, 11):
        k = int(lol, base)
        safe = False;
        for i in range(2, min(k, 100)):
            if(k % i == 0):
                safe = True;
                break;
        if not safe:
            died = True;
            break;
    if not died:
        sys.stdout.write(lol)
        for base in range(2, 11):
            k = int(lol, base)
            safe = False;
            for i in range(2, min(k, 100)):
                if(k % i == 0):
                    sys.stdout.write(" " + str(i));
                    break;
        count += 1
        sys.stdout.write('\n');

