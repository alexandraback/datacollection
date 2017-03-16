

def solve(tables):
    step = 0
    while len(tables) > 0:
        step += 1
        status = sum(tables)/float(len(tables))
        if status <= 2:
            tables = [t-1 for t in tables]
            tables = filter(lambda x: x != 0, tables)
        else:
            max_el = max(tables)
            modified = False
            new_tables = []
            for t in tables:
            #if t == 1:
            #    new_tables.append(t)
            #else:
            #    split = t/2
            #    new_tables.extend([t-split, split])
            #    break
                if t == max_el and not modified:
                    split = t/2
                    new_tables.extend([t-split, split])
                    modified = True
                else:
                    new_tables.append(t)
                
            tables = new_tables

        #print "step=%i, status=%f" % (step, status)
        #print tables
            
    return step

T = int(raw_input())
for t in xrange(T):
    D = int(raw_input())
    tables = map(int, raw_input().split())
    #print "=== NEW CASE ==="
    #print tables
    print "Case #%i: %i" % (t+1, solve(tables))
