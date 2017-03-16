# good luck debugging this

for TC in range(1, int(raw_input())+1):
    r, c, m = map(int, raw_input().split())
    empty = r * c - m
    
    print "Case #%d:" % TC
    
    if m == 0:
        print "c" + "." * (c-1)
        for i in range(r-1):
            print "." * c
    
    elif empty == 1:
        print "c" + "*" * (c-1)
        for i in range(r-1):
            print "*" * c
            
    elif r == 1:
        print "c" + "." * (empty-1) + "*" * (c-empty)
        
    elif c == 1:
        print "c"
        for i in range(empty-1):
            print "."
        for i in range(r-empty):
            print "*"
            
    elif empty in [2, 3, 5, 7]:
        print "Impossible"
        
    elif (r == 2 or c == 2) and empty % 2 == 1:
        print "Impossible"
        
    elif empty / 2 <= c:
        if empty % 2 == 0:
            print "c" + "." * (empty/2 - 1) + "*" * (c - empty/2)
            print "." * (empty/2) + "*" * (c - empty/2)
            for i in range(r-2):
                print "*" * c
        else:
            print "c" + "." * ((empty-3) / 2 - 1) + "*" * (c - (empty-3) / 2)
            print "." * ((empty-3) / 2) + "*" * (c - (empty-3) / 2)
            print "..." + "*" * (c-3)
            for i in range(r-3):
                print "*" * c
                
    else:
        full_rows_of_two = empty / (c*2)
        if empty - 2*full_rows_of_two*c == 1:
            if c > 3:
                for i in range(full_rows_of_two-1):
                    if i == 0:
                        print "c" + "." * (c-1)
                    else:
                        print "." * c
                    print "." * c
                print "." * (c-1) + "*"
                print "." * (c-1) + "*"
                print "..." + "*" * (c-3)
                for i in range(r-full_rows_of_two*2-1):
                    print "*" * c
            else:
                for i in range(full_rows_of_two-1):
                    if i == 0:
                        print "c" + "." * (c-1)
                    else:
                        print "." * c
                    print "." * c
                print "." * c
                print "." * (c-1) + "*"
                print "." * (c-1) + "*"
                for i in range(r-full_rows_of_two*2-1):
                    print "*" * c
        else:
            for i in range(full_rows_of_two):
                if i == 0:
                    print "c" + "." * (c-1)
                else:
                    print "." * c
                print "." * c
            rem = empty - 2*full_rows_of_two*c
            if rem - c == 1:
                print "." * (c-1) + "*"
                print ".." + "*" * (c-2)
                for i in range(r-full_rows_of_two*2-2):
                    print "*" * c
            else:
                if rem > c:
                    print "." * c
                    print "." * (rem - c) + "*" * (c*2 - rem)
                    for i in range(r-full_rows_of_two*2-2):
                        print "*" * c
                else:
                    print "." * rem + "*" * (c - rem)
                    for i in range(r-full_rows_of_two*2-1):
                        print "*" * c
