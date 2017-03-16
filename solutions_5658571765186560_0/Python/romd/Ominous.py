LINES_FOR_EACH_INPUT = 1
INPUT_FILE_NAME = 'D-small-attempt1.in'
OUTPUT_FILE_NAME = 'D-small-attempt1.out'

def do_case(parsed_input):
        x=int(parsed_input[0])
        r=int(min(parsed_input[1],parsed_input[2]))
        c=int(max(parsed_input[1],parsed_input[2]))
        if x>=7 or x>c or x/2+int(x/4)-int(x/5)+int(x/6)>r or (r*c)%x!=0:
                return "RICHARD"
        else:
                return "GABRIEL"

        return str(Max)

def do_parse(input):
        return input[0].rstrip().split(" ")
        

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
