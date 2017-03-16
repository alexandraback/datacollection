LINES_FOR_EACH_INPUT = 1
INPUT_FILE_NAME = 'D-large.in'
OUTPUT_FILE_NAME = 'D-large.out'

def do_case(parsed_input):
        x=int(parsed_input[0])
        r=int(min(parsed_input[1],parsed_input[2]))
        c=int(max(parsed_input[1],parsed_input[2]))
        if x>=7 or x>c or x/2+int((x-1)/3)>r or (r*c)%x!=0:
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
'''
the conditions to richard winning are as follows:
if x>=7 then he can choose an almost closed loop and win,
obviously R*c must divide by x and the maximum of them must be at least x,
so that richard cant win by simply choosing a straight line.
now the munumal conditions for the naroow side must be fo it to fit,
and not cut the board into two parts/
'''
