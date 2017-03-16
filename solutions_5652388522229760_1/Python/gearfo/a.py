import argparse

parser = argparse.ArgumentParser()
parser.add_argument('infile')
args = parser.parse_args()


def sheep(n): 
        d = {}
        unseen = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0']
        i = 1
        while True:
            N = str(n * i)
            for u in unseen[:]:
                if u in N:
                    unseen.remove(u)
            if unseen == []:
                return i * n
            else:
                i += 1


with open(args.infile, 'r') as infile:
    infile.readline()
    j = 1
    for line in infile:
        n = int(line)
        if n == 0:
            answer = "INSOMNIA"
        else:
            answer = sheep(n)
        print("Case #%s: %s" % (j, answer))
        j += 1
