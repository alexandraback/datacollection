package oneb;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class B
{
    private static final String PATH_HOME = "y:/codejam/repository/projects/2014";

    private static final String PATH_INPUT = PATH_HOME + "/input/B-small-attempt0.in";

    private static final String PATH_OUTPUT = PATH_HOME + "/output/B-small-attempt0.out";

    private static List<String> readInput() throws IOException
    {
        List<String> tokens = new ArrayList<>();

        try ( BufferedReader reader = Files.newBufferedReader( Paths.get( PATH_INPUT ), Charset.forName( "UTF-8" ) ) )
        {
            String line = null;
            while ( ( line = reader.readLine() ) != null )
            {
                for ( String token : line.split( "\\s" ) )
                {
                    if ( !token.isEmpty() )
                    {
                        tokens.add( token );
                    }
                }
            }
        }

        return tokens;
    }

    private static void writeOutput( List<String> results ) throws IOException
    {
        try ( BufferedWriter writer = Files.newBufferedWriter( Paths.get( PATH_OUTPUT ), Charset.forName( "UTF-8" ) ) )
        {
            for ( int i = 0; i < results.size(); i++ )
            {
                writer.write( "Case #" + ( i + 1 ) + ": " + results.get( i ) );
                if ( i < results.size() - 1 )
                {
                    writer.newLine();
                }
            }
        }
    }

    public static void main( String[] args ) throws IOException
    {
        List<String> tokens = readInput();

        int cases = Integer.valueOf( tokens.remove( 0 ) );
        for ( int i = 0; i < cases; i++ )
        {
            final long a = Long.valueOf( tokens.remove( 0 ) );
            final long b = Long.valueOf( tokens.remove( 0 ) );
            final long k = Long.valueOf( tokens.remove( 0 ) );

            long count = 0;
            for ( int l = 0; l < a; l++ )
            {
                for ( int m = 0; m < b; m++ )
                {
                    if ( ( l & m ) < k )
                    {
                        count++;
                    }
                }
            }
            tokens.add( "" + count );
        }

        writeOutput( tokens );
    }
}
