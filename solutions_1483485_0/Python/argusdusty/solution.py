import sys

mapping = {32: ' ', 97: 'y', 98: 'h', 99: 'e', 100: 's', 101: 'o', 102: 'c', 103: 'v', 104: 'x', 105: 'd', 106: 'u', 107: 'i', 108: 'g', 109: 'l', 110: 'b', 111: 'k', 112: 'r', 113: 'z', 114: 't', 115: 'n', 116: 'w', 117: 'j', 118: 'p', 119: 'f', 120: 'm', 121: 'a', 122: 'q'}

def speaking_in_tongues(args):
    return args.translate(mapping)

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    for i in range(1, int(Input[0]) + 1):
        args = Input[i]
        result = speaking_in_tongues(args)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
