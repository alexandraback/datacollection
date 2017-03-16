import sys

def main(filepath):
	with file('password_output.txt', 'wb') as f_out:
		with file(filepath, 'rb') as f_in:
			for line_index, line in enumerate(f_in):
				if line_index == 0: #T
					continue
				if line_index % 2:
					input_list = line.strip().split(' ')
					already_typed = int(input_list[0])
					pass_len = int(input_list[1])
				else:
					input_list = line.strip().split(' ')
					prob_list = []
					for prob_str in input_list:
						prob_list.append(float(prob_str))
					print "typed: %d, len: %d, list: %s" % (already_typed, pass_len, prob_list)
				
					expected = float(2 + pass_len) #from give up
					
					for backspace in xrange(already_typed + 1):
						n = already_typed - backspace
						tmp_expected = 1 + backspace
						pos = 1
						for i in xrange(n):
							pos *= prob_list[i]
						neg = 1 - pos
						tmp_expected += pos * (pass_len - n)
						tmp_expected += neg * (pass_len - n + pass_len + 1)
						if tmp_expected < expected:
							expected = tmp_expected
					
					f_out.write("Case #%d: %0.6f\n" % (line_index / 2, expected))
				
if __name__ == '__main__':
	main(sys.argv[1])