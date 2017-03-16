size = 2000000
sieve = [[]]
for n in xrange(1, size + 1):
    sieve.append([])
    string = str(n)
    for i in xrange(1, len(string)):
        if string[i] != "0":
            recyc = string[i:] + string[:i]
            if int(recyc) > n:
                if int(recyc) not in sieve[n]:
                    sieve[n].append(int(recyc))

print "Sieving complete"

outfile = open("c_out.txt", "w")
count = 0
for line in open("C-small-attempt0.in", "rU"):
    if count != 0:
        line = line.strip()
        listy = line.split(" ")
        a = int(listy[0])
        b = int(listy[1])
        total = 0
        for i in xrange(a, b+1):
            for number in sieve[i]:
                if number <= b:
                    total += 1
                    #print i, number
        outfile.write("Case #" + str(count) + ": " + str(total) + "\n")
        print "Case " + str(count) + " complete"
    count += 1

outfile.close()
