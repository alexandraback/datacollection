TRANSLATION_SEEDS = {
    'ejp mysljylc kd kxveddknmc re jsicpdrysi': 'our language is impossible to understand',
    'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd': 'there are twenty six factorial possibilities',
    'de kr kd eoya kw aej tysr re ujdr lkgc jv': 'so it is okay if you want to just give up',
}

ALPHABET = 'abcdefghijklmnopqrstuvwxyz'

class GoogleTongueTranslator(object):

    def __init__(self):
        self.translate_dictionary = {' ': ' ',
                                     'y': 'a',
                                     'e': 'o',
                                     'q': 'z',
                                     'z': 'q'}
        for k, v in TRANSLATION_SEEDS.iteritems():
            self.seed_translator(k, v)

    def seed_translator(self, googlerese, english):
        clean_googlerese = ''.join(googlerese.split(' '))
        clean_english = ''.join(english.split(' '))
        for i in range(len(clean_googlerese)):
            self.translate_dictionary[clean_googlerese[i]] = clean_english[i]

    def translate(self, googlerese):
        return ''.join([self.translate_dictionary.get(char, ' ') for char in googlerese])

translator = GoogleTongueTranslator()

input_file = '/tmp/01_tongues.in'
output_file = '/tmp/01_tongues.out'

class InputReader(object):

    def __init__(self, input_file, output_file):
        self.translator = GoogleTongueTranslator()

        self.input = input_file
        self.input_buffer = []

        self.output = output_file
        self.output_buffer = []

    def run(self):
        self.initialize()
        self.generate_answer()
        self.write_output()

    def initialize(self):
        with open(self.input, 'r') as f:
            for line in f:
                self.input_buffer.append(line)

    def generate_answer(self):
        self.case_count = int(self.input_buffer[0])
        for line in self.input_buffer[1:]:
            self.output_buffer.append(self.translator.translate(line))

    def write_output(self):
        with open(self.output, 'w') as f:
            index = 1
            for line in self.output_buffer:
                x = 'Case #{0}: {1}\n'.format(index, line)
                f.write(x)
                index += 1


reader = InputReader(input_file, output_file)
reader.run()
