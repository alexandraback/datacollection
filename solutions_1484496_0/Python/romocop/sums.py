# Round 1A 2012
# A. Safety in Numbers
# Roman Stolper (romocop)

# imports
import sys;
import string;
import fractions;
import operator;

def main():
    # get input filename from command line args
    if (len(sys.argv) != 2):
        print "Must specify input file!";
        return 1;

    inputFile = str(sys.argv[1]);
    outputFile = inputFile + ".out";
        
    # open input file
    f_in = open(inputFile, 'r');
    f_out = open(outputFile, 'w');
    
    runTests(f_in, f_out);

    f_in.close();
    f_out.close();

def runTests(f_in, f_out):
    numTests = int(f_in.readline());
    for i in range(0, numTests):
        runTest(f_in, f_out, i+1);

def runTest(f_in, f_out, testNum):
    (N) = parseInput(f_in);
    S = getSubsets(N);
    print S;
    result = "";
    for i in range(0, len(S)):
        result += "\n";
        x = list();
        for j in range(0, len(S[i])):
            x.append(str(N[S[i][j]]));
        result += string.join(x, " ");
        #result += string.join(S[i]);
        #result += "\n";
        #result += string.join(S[1]);
    result_out = "Case #" + str(testNum) + ":" + result + "\n";
    print result_out;
    f_out.write(result_out);
    
def parseInput(f_in):
    line = f_in.readline();
    pieces = string.split(line);
    n = int(pieces[0]);
    N = list();
    for i in range(1, len(pieces)):
        N.append(int(pieces[i]));
    return N;
    
def getSubsets(N):
    allSums = dict();
    currSets = list();
    currSetSize = 1;
    for i in range(0, len(N)):
        currSets.append([i]);
        allSums[N[i]] = [i];
    
    nextSets = list();
    while(currSetSize < N):
        print currSets;
        print allSums;
        # generate sets of next set size
        # for each set, check if the sum has been seen before
        # if has, we have have a winner
        # if not, add to nextSets and put its sum in allSums
        # set currSets = nextSets
        for i in range(0, len(currSets)):
            set = currSets[i];
            # get last index in the set
            lastIdx = set[len(set)-1];
            for j in range(lastIdx + 1, len(N)):
                nextSet = set + [j];
                setSum = 0;
                for k in range(0, len(nextSet)):
                    setSum += N[nextSet[k]];
                if (setSum in allSums):
                    print "found sum: " + str(setSum);
                    return [nextSet, allSums[setSum]];
                else:
                    nextSets.append(nextSet);
                    allSums[setSum] = nextSet;
        currSets = nextSets;
        
    print N;
    
    
main();