import argparse
import math

def function():
    pass

def filtered(s):
    currentchar = s[0]
    currentstr = "" + currentchar
    for c in s:
        if c == currentchar:
            continue
        else:
            currentchar = c
            currentstr = currentstr + currentchar
    return currentstr
    
def filtered2(s):
    return s[0] + s[-1]
                
def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        num_cases = int(f_in.readline().strip())
        for i in range(num_cases):
            num_strings = int(f_in.readline().strip())
            strings = (f_in.readline().split())
            print(strings)
            strings = [filtered(s) for s in strings]
            print(strings)
            
            dict = {}
            for c in "abcdefghijklmnopqrstuvwxyz":
                dict[c] = [0,0,0,0]
            
            onetypes = []
            others = []
            for s in strings:
                if len(s) == 1:
                    dict[s] = [dict[s][0] + 1] + dict[s][1:]
                else:
                    c = s[0]
                    dict[c] = dict[c][:1] + [dict[c][1] + 1] + dict[c][2:]
                    c = s[-1]
                    dict[c] = dict[c][:2] + [dict[c][2] + 1] + dict[c][3:]
                    for c in s[1:-1]:
                        dict[c] = dict[c][:-1] + [dict[c][3] + 1]
            
            print(dict)
            
            totalcombs = 1
            numchains = 0
            for x in dict.values():
                if x[3] > 1 or (x[3] == 1 and (x[0] >= 1 or x[1] >= 1 or x[2] >= 1)):
                    totalcombs = 0
                    print("case 1 FAIL")
            for s in strings:
                if len(s) >= 2 and s[0] == s[-1]:
                    totalcombs = 0
                    print("case 2 FAIL")

            strings = [filtered2(s) for s in strings]
            print("finalfiltered strs =")
            print(strings)
            
            for k in dict.keys():
                if dict[k][0] >= 1 and dict[k][1] == 0 and dict[k][2] == 0 and dict[k][3] == 0:
                    totalcombs *= math.factorial(dict[k][0])
                    totalcombs = totalcombs % 1000000007
                    numchains += 1
                    print("found 1 {}".format(k))
                    print(dict[k])
                    print("{} {}".format(totalcombs, numchains))
                elif dict[k][0] >= 1 and dict[k][1] <= 1 and dict[k][2] <= 1 and dict[k][3] == 0:
                    totalcombs *= math.factorial(dict[k][0])
                    totalcombs = totalcombs % 1000000007
                    print("found 2 {}".format(k))
                    print(dict[k])
                    print("{} {}".format(totalcombs, numchains))
                elif dict[k][1] >= 2 or dict[k][2] >= 2:
                    totalcombs = 0
                    print("case 3 FAIL {}".format(k))
                    
            onetypes = []
            twotypes = []
            for s in strings:
                if s[0] == s[1]:
                    onetypes += [s]
                else:
                    twotypes += [s]
            print("BREAK------------")
            print(onetypes)
            print(twotypes)
                    
                    
            # each letter begins at most one string and ends at most one string
            #turn twotypes into chains
            #repeatedly: find a chain starter            
            while len(twotypes) > 0:
                print("starting monster loop, len = {}".format(len(twotypes)))
                beginChainStarter = twotypes[0]
                currChainStarter = twotypes[0]
                print("currChainStarter = {}".format(currChainStarter))
                progress = True
                while progress:
                    progress = False
                    for x in twotypes:
                        if currChainStarter[0] == x[1]:
                            progress = True
                            currChainStarter = x
                            print("update: chainstarter = {}".format(currChainStarter))
                            if currChainStarter == beginChainStarter:
                                totalcombs = 0
                                progress = False
                                print("LOOOOOOP FAIL")
                            break
                # currChainStarter is a real chain starter (no cycles here), build the chain
                twotypes.remove(currChainStarter)
                numchains += 1
                endingchar = currChainStarter[1]
                print("building chain")
                print("adding {}".format(currChainStarter))
                progress = True
                while progress:
                    progress = False
                    for x in twotypes[:]:
                        if x[0] == endingchar:
                            twotypes.remove(x)
                            print("adding {}".format(x))
                            endingchar = x[1]
                            progress = True
                            break            
                
            result = (math.factorial(numchains) * totalcombs) % 1000000007
            
            outputline = "Case #{}: {}\n".format(i + 1, result)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        