LINES_FOR_EACH_INPUT = 2
INPUT_FILE_NAME = 'C-small-attempt1.in'
OUTPUT_FILE_NAME = 'C-small-attempt1.out'
quartMultTable={'oo':'o','oi':'i','oj':'j','ok':'k',
                'io':'i','ii':'O','ij':'k','ik':'J',
                'jo':'j','ji':'K','jj':'O','jk':'i',
                'ko':'k','ki':'j','kj':'I','kk':'O'
                }

def quartMult(input):
        a=input
        while len(a)>1:
                a=quart2Mult(a[:2])+a[2:]
        return a
def quart2Mult(input):
        if input.islower() or input.isupper():
                return quartMultTable[input.lower()]
        else:
                return quartMultTable[input.lower()].swapcase()
def do_case(parsed_input):
        a=parsed_input
        while len(a)>1 and a[0]!='i' :
                a=quart2Mult(a[:2])+a[2:]
        if len(a)==1:
                return 'NO'
        else:
                a=a[1:]
        while len(a)>1 and a[0]!='j' :
                a=quart2Mult(a[:2])+a[2:]
        if len(a)==1:
                return 'NO'
        else:
                return 'YES'

def do_parse(input):
        parsed=''
        word=input[1].rstrip()
        mult=quartMult(word)
        ret=int(input[0].split(' ')[1].rstrip())
        if (mult=='o')or(mult=='O' and ret%2==0)or(mult!='o' and mult!='O' and ret%4!=2):
                return 'k'
        else:
                for i in range(0,min(8,ret)):
                        parsed=parsed+word
        return parsed

def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
	
        input_lines = input_f.readlines()
	
        for test_case in range(num_of_test_cases):
                parsed_input = do_parse(input_lines[test_case*LINES_FOR_EACH_INPUT : (test_case + 1) * LINES_FOR_EACH_INPUT])
                output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
