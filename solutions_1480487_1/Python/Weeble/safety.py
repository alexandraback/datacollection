from __future__ import division

def solvecase(judgescores):
    bigx = sum(judgescores)
    number = len(judgescores)
    for index, judgescore in enumerate(judgescores):
        all_others = sorted(judgescores)
        all_others.remove(judgescore)
        judge_sum = judgescore
        for competitor_count in xrange(1,len(all_others)):
            # Suppose all the other points are distributed to
            # all_others[:competitor_count] in such a way that
            # they have equal scores to ours.
            judge_sum = judgescore + sum(all_others[:competitor_count])
            allocated_points = bigx
            avg = (judge_sum + allocated_points) / (competitor_count + 1)
            #print "avg", avg, "cc", competitor_count
            if (competitor_count + 1)<number and avg > all_others[competitor_count]:
                continue
            #print "cc", competitor_count
            score_needed = avg - judgescore
            if score_needed < 0:
                yield 0.0
            else:
                #print "***", score_needed, "&&&"
                yield 100 * score_needed / bigx
            break
        else:
        #shared = (2 * bigx - number * judgescore) / number
        #for o in judgescores:
        #    if o > shared:
        #        print "PROBLEM!"
        #        print judgescores, judgescore, shared
            yield max(0, 100 * (2 * bigx - number * judgescore) / (number * bigx))

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        values = [int(s) for s in raw_input().split()]
        results = list(solvecase(values[1:]))
        print "Case #{0}: {1}".format(i+1, " ".join(map(str,results)))

if __name__ == "__main__":
    main()

