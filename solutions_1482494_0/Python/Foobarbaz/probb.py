import os

def comparator(x, y):
    ## Just a condition for example,
    ## you can add as many you need.
    return x[0]-y[0]

## Initial Array

#array = [(8,1), (2,1), (9,1)];
#array.sort(comparator)
#print array


#f = open("test.pb","r")

f = open("B-small-attempt1.in","r")
#f = open("A-large.in","r")

s = f.readline()
ntrials = int(s)

i =0

fout = open("probb.out","w")


def get_next_b(tups,i):
    for j in xrange(i,len(tups)):
        #print "lookign at up ", tups[j]
        if (tups[j][1] == 'b'):
            return j
    #print "failed to find b"
    return -1

def vals(tups):
    cur_stars = 0
    cur_hops = 0
    used_a = []
    avail_a = []
    avail_a = []
    i= 0
    print "hello"
    while cur_stars < len(tups):
        next_b = get_next_b(tups,i)
        print "starting at i,next_b", i, next_b
        next_b_tup = tups[next_b]
        if (next_b_tup[0] <= cur_stars):
            for l in xrange(i,next_b):
                avail_a.append(tups[l][2])
            cur_hops +=1
            assert (tups[next_b][1] == 'b')
            if tups[next_b][2] in used_a:
                print "using b and a", tups[next_b][2]
                cur_stars +=1
            else:
                print "using b", tups[next_b][2]
                print "removing from avail a", tups[next_b][2]
                avail_a.remove(tups[next_b][2])
                cur_stars += 2
            i = next_b+1
        else:
            stars_needed = next_b_tup[0] - cur_stars
            tween_stars = next_b -i 
            past_stars = len(avail_a)
            if (tween_stars +past_stars< stars_needed):
                return -1
            else:
                for old in xrange(len(avail_a)):
                    if (stars_needed==0):
                        break;
                    else:
                        stars_needed-=1
                        print "poping from avail_a ", avail_a[0]
                        used_a.append(avail_a.pop(0))
                        #avail_a.pop(0)
                for l in xrange(stars_needed):
                    index = i+l
                    assert(index < next_b)
                    if (cur_stars >= tups[index][0]):
                        cur_stars+=1
                        used_a.append(tups[index][2])
                    else:
                        return -1
                for l in xrange(stars_needed,tween_stars):
                    index = i+l
                    print "adding to avail_a ", tups[index][2]
                    avail_a.append(tups[index][2])
                cur_hops += stars_needed
            i = next_b

    print "returning hops,stars,len(tups)", cur_hops,cur_stars, len(tups)
    return cur_hops
            
for i in xrange(1,ntrials+1):
    line = f.readline()
    fields = line.split()
    N = int(fields.pop(0))
    ughs = []
    for j in xrange(N):
        line = f.readline()
        fields = line.split()
        ughs.append((int(fields[0]),"a",j))
        ughs.append((int(fields[1]),"b",j))
    #sughs = sort_by_onish(ughs)
    ughs.sort(comparator)
    #print "tups are ", ughs
    result = vals(ughs)
    if (result < 0):
        fout.write("Case #" +str(i) + ": Too Bad \n")
    else:
        fout.write("Case #" +str(i) + ": " + str(result) +"\n")
    
fout.close()
os.system("cat probb.out")

