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
    (S) = parseInput(f_in);
    minimums = getMinimums(S);
    result = "";
    for i in range(0, len(minimums)):
        result += " {0:.6f}".format(minimums[i]);
    result_out = "Case #" + str(testNum) + ":" + result + "\n";
    print result_out;
    f_out.write(result_out);
    
def parseInput(f_in):
    line = f_in.readline();
    pieces = string.split(line);
    S = list()
    for i in range(1, len(pieces)):
        si = int(pieces[i]);
        #S[si] = i-1;
        S.append((si, i-1, 0));
    return S;
    
def getMinimums(S):
    #print "minimums: " + str(S);
    #return [0, 1, 2];
    minimums = [0] * len(S);
    X = sum([pair[0] for pair in S]);
    Ssort = sorted(S, key=operator.itemgetter(0));
    #print Ssort;
    sumS = 0;
    # precalc the sum
    for i in range(0, len(Ssort)):
        sumS += Ssort[i][0];
        #sumS = Ssort[i-1][2] + Ssort[i][0];
        Ssort[i] = (Ssort[i][0], Ssort[i][1], sumS);
        #print Ssort[i][2];
    
    remY = float(1.0);
    for i in range(len(S)-1, 0, -1):
        s = Ssort[i][0];
        diff = (i)*s - Ssort[i-1][2];
        yNeeded = float(diff)/float(X);
        if (diff >= X):
            minimum = float(0.0);
        else:
            minimum = float(remY - yNeeded) / float(i+1);
        print "S: "+str(s)+", diff: "+str(diff)+", yneed: "+str(yNeeded)+", yrem: " + str(remY) + ", min: " + str(minimum);
        remY -= minimum;
        #minimum = float(100) * float(s2 - s1 + X) / float(2*X);
        minimums[Ssort[i][1]] = float(100)*minimum;
    minimums[Ssort[0][1]] = float(100)*remY;
    return minimums;
    
main();
    