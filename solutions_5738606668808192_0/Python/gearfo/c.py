from __future__ import print_function
import argparse



def n_to_10(string, n):
    s = string[::-1]
    j = 0
    num = 0
    for j in range(len(s)):
        if s[j] == '1':
            num += n ** j
    return num

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('infile')
    args = parser.parse_args()
    with open(args.infile, 'r') as infile:
        infile.readline()
        j = 1
        for line in infile:
            words = line.split()
            N = int(words[0])
            J = int(words[1])
            answer = ""
            # loop over potential jamcoin strings
            for i in range(2**14):
                br = str(bin(i)[2:])
                candidate = '1' + '0' * (N - len(br) - 2) + br + '1'
                #print(candidate)

                
                # in every base:
                reps = [n_to_10(candidate, p) for p in  range(2,11)]
                #print(reps)
                
                # list of factors
                factors = []
                
                for r in reps:
                    for f in range(2, 250): # look for factors smaller than this
                        if r % f == 0:
                            factors.append(f)
                            break
                if len(factors) == 9:
                    answer += '\n'
                    answer += candidate + ' '
                    answer += ' '.join([str(w) for w in factors])
                    J -= 1
                    #print (candidate, factors)
                if J == 0:
                    break
            print("Case #%s: %s" % (j, answer))
            j += 1

if __name__=='__main__':
    main()
